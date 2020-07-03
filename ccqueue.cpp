
// Description:  Implmentation of a customer complaint queue class

#include "ccqueue.h"

CCQueue :: CCQueue()
{
  DLinkedList<Ticket> *tickets = new DLinkedList<Ticket>;
  maxticketid = 0;
}

bool CCQueue::Add(string customer, string complaint)
{
  if (customer.length() == 0 || complaint.length() == 0)
  {
    return false;
  }
  else
  {
    Ticket NewTicket = Ticket(maxticketid + 1, customer, complaint);

    tickets.InsertBack(NewTicket);

    maxticketid++;
    return true;
  }
}

Ticket CCQueue::Service()
{
  if (tickets.IsEmpty() == true)
  {
    throw std::out_of_range("Empty List");
  }
  
  Ticket RemovedTicket = tickets.RemoveAt(0);

  return RemovedTicket;
}

bool CCQueue::MoveUp(int index)
{
  if (index <= 0 || index >= tickets.Size())
  {
    return false;
  }

  Ticket RemovedTicket = tickets.RemoveAt(index);
  tickets.InsertAt(RemovedTicket, index - 1);

  return true;
}

bool CCQueue::MoveDown(int index)
{
  if (index >= tickets.Size() - 1 || index < 0)
  {
    return false;
  }

  Ticket RemovedTicket = tickets.RemoveAt(index);
  tickets.InsertAt(RemovedTicket, index + 1);

  return true;
}

int CCQueue::Size() const
{
  return tickets.Size();
}
