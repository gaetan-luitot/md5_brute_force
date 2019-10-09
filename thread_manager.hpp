#ifndef THREAD_MANAGER_HPP
#define THREAD_MANAGER_HPP

#include <cstdint>
#include <pthread.h>
#include "word.hpp"
#include "utilities.hpp"
#include <string>

struct data
{
    size_t id;
    uint64_t where_init;
    uint64_t nb_turns;
    bool has_finished = true;
    void * manager;
};



class ThreadManager
{
private:
    uint16_t _nb_thread;
    uint64_t _nb_turns;
    pthread_t * _threads;
    data * _thread_data;
    uint64_t _current_max_search;
    Word _result;
    bool _resultFound;
    std::string _md5;

public:
    ThreadManager() = delete;
    ThreadManager(uint16_t nb_thread, std::string md5, uint64_t nb_turns = 65536);
    ~ThreadManager();
    pthread_t * at(uint16_t i) const;
    void startThread(uint16_t i);
    // void stopAllThreads() const; 
    bool getFirstWaitingThread(uint16_t & res) const;
    inline bool resultFound() const { return _resultFound; };
    inline Word getResult() { return _result; };
    inline std::string getMD5() const { return _md5; };
    void setResult(Word res);

};

#endif /* end of include guard: THREAD_MANAGER_HPP */
