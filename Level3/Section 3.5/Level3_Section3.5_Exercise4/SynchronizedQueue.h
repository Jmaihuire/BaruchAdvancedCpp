#pragma once
// Queue class that has thread synchronisation (pulled from lecture slides)
// but converted to stl 
#ifndef __SYNCH_QUEUE_
#define __SYNCH_QUEUE_

#include <mutex>
#include <queue>

template <typename T>
class SynchronizedQueue {
 private:
  std::priority_queue<T> m_queue;  // Use stl PRIORITY queue to store data
  std::mutex m_mutex;              // The mutex (used for synchronization) 
  std::condition_variable m_cond;  // The condition to wait for
 public:

  // Add data to the queue
  // notify others
  void Enqueue(const T& data) {
    std::unique_lock<std::mutex> lock(m_mutex); //lock queue 
    m_queue.push(data);
    m_cond.notify_one(); // this notifies others that queue is ready 
  };  // Lock is released here

  // Get data from the queue. Wait for data if not available
  T Dequeue() {
    std::unique_lock<std::mutex> lock(m_mutex); // this locks queue 
    // When there is no data, wait till someone fills it
    // Lock is automatically released in the wait and active again after the
    // wait
    while (m_queue.size() == 0) m_cond.wait(lock);
    // Retrieve the data from the queue
    T result = m_queue.top();
    m_queue.pop();  // change to top() function since we are using priority
                    // queue now
    return result;
  };  // Lock is released here
};

#endif
