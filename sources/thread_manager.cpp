#include "../headers/thread_manager.hpp"
#include "../headers/word.hpp"
#include <stdexcept>
#include <iostream>

// --- THREAD'S METHOD :
void * func(void * arg)
{
    data * infos = (data *)arg;

    Word tmp_word(infos->where_init);

    for (__uint128_t i = 0; i < infos->nb_turns && !((ThreadManager*)infos->manager)->resultFound(); ++i, ++tmp_word)
    {
        if (cpp_md5sum((tmp_word).getString()) == ((ThreadManager*)infos->manager)->getMD5())
        {
            ((ThreadManager*)infos->manager)->setResult(tmp_word);
        }
    }

    infos->has_finished = true;

    return arg;
}

//
// --- THREADMANAGER'S METHODS :
//

ThreadManager::ThreadManager(uint16_t nb_thread, std::string md5, uint64_t nb_turns)
: _nb_thread(nb_thread), _nb_turns(nb_turns), _threads(nullptr) ,_thread_data(nullptr),
_current_max_search(0), _result('0'), _resultFound(false), _md5(md5)
{
    _threads = new pthread_t[_nb_thread];
    _thread_data = new data[_nb_thread];

    // Initialisations des infos des threads :
    for (size_t i = 0; i < _nb_thread; i++)
    {
        _thread_data[i].id = i;
        _thread_data[i].manager = this;
        _thread_data[i].nb_turns = _nb_turns;
        _thread_data[i].where_init = 0;
    }
}



ThreadManager::~ThreadManager()
{
    delete [] _thread_data;
    delete [] _threads;
}

void ThreadManager::startThread(uint16_t i)
{
    if (i > _nb_thread)
        throw std::out_of_range("ThreadManager::startThread() -> The given argument is too big.");

    if (!_thread_data[i].has_finished)
        throw std::invalid_argument("ThreadManager::startThread() -> The given thread still running.");

    if (!_resultFound)
    {
        _thread_data[i].has_finished = false;
        _thread_data[i].where_init = _current_max_search;
        pthread_create(at(i), NULL, func, (void *)&_thread_data[i]);
        _current_max_search += _nb_turns;
    }
}

/*
void ThreadManager::stopAllThreads() const
{
    for (size_t i = 0; i < _nb_thread; i++)
    {
        if (!_thread_data[i].has_finished)
        {
            //_thread_data[i].has_finished = true;
            pthread_cancel(_threads[i]);
        }
    }

}
*/

pthread_t * ThreadManager::at(uint16_t i) const
{
    if (i > _nb_thread)
        throw std::out_of_range("ThreadManager::at() -> The given argument is too big.");

    return &_threads[i];
}

bool ThreadManager::getFirstWaitingThread(uint16_t & res) const
{
    for (size_t i = 0; i < _nb_thread; i++)
    {
        if (_thread_data[i].has_finished)
        {
            res = i;
            return true;
        }
    }

    return false;
}

void ThreadManager::setResult(Word res)
{
    _result = res;
    _resultFound = true;
    //stopAllThreads();
}
