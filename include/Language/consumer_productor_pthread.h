//
// Created by ruoting on 2019/11/28.
//

#ifndef CODING_CONSUMER_PRODUCTOR_PTHREAD_H
#define CODING_CONSUMER_PRODUCTOR_PTHREAD_H

#include <iostream>
#include <queue>
#include <pthread.h>

namespace consumer_productor {
    class BlockQueue {
    public:
        BlockQueue(int cap = 10) : _capacity(cap) {
            pthread_mutex_init(&_mutex, NULL);
            pthread_cond_init(&_cond_productor, NULL);
            pthread_cond_init(&_cond_consumer, NULL);
        }

        ~BlockQueue() {
            pthread_mutex_destroy(&_mutex);
            pthread_cond_destroy(&_cond_productor);
            pthread_cond_destroy(&_cond_consumer);
        }

        bool QueuePush(int data) {
            pthread_mutex_lock(&_mutex);
            while (_queue.size() == _capacity) {
                pthread_cond_wait(&_cond_productor, &_mutex);
            }
            _queue.push(data);
            pthread_cond_signal(&_cond_consumer);
            pthread_mutex_unlock(&_mutex);
            return true;
        }

        bool QueuePop(int *data) {
            pthread_mutex_lock(&_mutex);
            while (_queue.empty()) {
                pthread_cond_wait(&_cond_consumer, &_mutex);
            }
            *data = _queue.front();
            _queue.pop();
            pthread_cond_signal(&_cond_productor);
            pthread_mutex_unlock(&_mutex);
            return true;
        }

    private:
        std::queue<int> _queue;
        int _capacity;
        pthread_mutex_t _mutex;
        pthread_cond_t _cond_productor;
        pthread_cond_t _cond_consumer;
    };

    int total_count = 50;

    void *thr_consumer(void *arg) {
        BlockQueue *q = (BlockQueue *) arg;
        while (1) {
            int data;
            q->QueuePop(&data);
            std::cout << "consumer get data:" << data << std::endl;
            if (data >= total_count) {
                break;
            }
        }
        return NULL;
    }

    void *thr_productor(void *arg) {
        int i = 0;
        BlockQueue *q = (BlockQueue *) arg;
        while (i <= total_count) {
            std::cout << "productor put data:" << i << std::endl;
            q->QueuePush(i++);
        }
        return NULL;
    }

    void Test() {
        pthread_t ctid, ptid;
        BlockQueue q;
        int ret;

        ret = pthread_create(&ctid, NULL, thr_consumer, (void *) &q);
        if (ret != 0) {
            std::cout << "pthread create error\n";
        }

        ret = pthread_create(&ptid, NULL, thr_productor, (void *) &q);
        if (ret != 0) {
            std::cout << "pthread create error\n";
        }
        pthread_join(ctid, NULL);
        pthread_join(ptid, NULL);
    }
};


#endif //CODING_CONSUMER_PRODUCTOR_PTHREAD_H
