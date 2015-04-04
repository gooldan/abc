#include "ReceivedBuffer.h"
#include "QtCore\qsharedpointer.h"

template <class Type>
ReceivedBuffer<Type>::ReceivedBuffer(int size)
{
	Vacant = new boost::interprocess::interprocess_semaphore (size);
	Used = new boost::interprocess::interprocess_semaphore (0);
	mtx = new boost::interprocess::interprocess_mutex;
}

template <class Type>
ReceivedBuffer<Type>::~ReceivedBuffer(void)
{
	delete Vacant;
	delete Used;
	delete mtx;
}

template <class Type>
void ReceivedBuffer<Type>::Enqueue (Type a)
{
  Vacant->wait();
  mtx->lock();
    queue.push (a);
  mtx->unlock();
  Used->post();
}

template <class Type>
Type ReceivedBuffer<Type>::Dequeue ()
{
  Used->wait();
  mtx->lock();
    Type value = queue.front();
    queue.pop ();
  mtx->unlock();
  Vacant->post();
  return value;
}

template class ReceivedBuffer<int>;
template class ReceivedBuffer< QSharedPointer<KinectData> >;
template class ReceivedBuffer< QSharedPointer<NanoReceived> >;
template class ReceivedBuffer< QSharedPointer<ArduCopterReceived> >;
template class ReceivedBuffer< QSharedPointer<CameraReceived> >;
template class ReceivedBuffer< QSharedPointer<Command> >;
template class ReceivedBuffer< QSharedPointer<Send> >;