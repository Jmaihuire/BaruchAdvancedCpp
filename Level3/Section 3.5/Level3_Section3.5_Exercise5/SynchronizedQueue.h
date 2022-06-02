// Queue class that has thread synchronisation 
// pulled from lecture slides but changed to stl 
#ifndef __SYNCH_QUEUE_
#define __SYNCH_QUEUE_

#include <mutex>
#include <queue>

template <typename T>
class SynchronizedQueue {
 private:
  std::priority_queue<T> m_queue;  // Use stl queue to store data
  std::mutex m_mutex;              // The mutex to synchronise on
  std::condition_variable m_cond;  // The condition to wait for
 public:
  // Add data to the queue and notify others
  void Enqueue(const T& data) {
    // Acquire lock on the queue
    std::unique_lock<std::mutex> lock(m_mutex);
    // Add the data to the queue
    m_queue.push(data);
    // Notify others that data is ready
    m_cond.notify_one();
  };  // Lock is released here

  // Get data from the queue. Wait for data if not available
  T Dequeue() {
    // Acquire lock on the queue
    std::unique_lock<std::mutex> lock(m_mutex);
    // When there is no data, wait till someone fills it
    // Lock is automatically released in the wait and active again after the
    // wait
    while (m_queue.size() == 0) m_cond.wait(lock);
    // Retrieve the data from the queue
    T result = m_queue.top();
    m_queue.pop();  // use top instead of front for priority queue
    return result;
  };  // Lock is released here
};

#endif
