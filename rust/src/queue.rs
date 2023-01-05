use std::borrow::{Borrow, BorrowMut};
use std::ops::{Deref, DerefMut};
use std::rc::Rc;
use std::cell::RefCell;

struct QueueNode<T: Copy> {
    data: T,
    next: Option<Rc<RefCell<QueueNode<T>>>>
}

impl<T: Copy> QueueNode<T> {
    pub fn new(data: T) -> QueueNode<T> {
        QueueNode::<T> {data, next:None}
    }
}

struct Queue<T: Copy> {
    tail: Option<Rc<RefCell<QueueNode<T>>>>,
    size: usize
}

impl<T: Copy> Queue<T> {
    pub fn new() -> Queue<T> {
        Queue::<T>{tail: None, size: 0}
    }

    pub fn enqueue(&mut self, data: T) {
        let mut new_node = Rc::new(RefCell::new(QueueNode::<T>::new(data)));
        match self.tail {
            None => {
                (*new_node).borrow_mut().next = Some(Rc::clone(&new_node));
                self.size = self.size + 1;
                self.tail = Some(new_node);
            },
            Some(ref tail) => {
                (*new_node).borrow_mut().next = Some(Rc::clone(&*tail));
                self.size = self.size + 1;
                self.tail = Some(new_node);
            }
        }
    }

    pub fn dequeue(&mut self) -> Option<T> {
        if self.is_empty() {
            None
        } else {
            let tail = Rc::clone(self.tail.as_ref().unwrap());
            let front = Rc::clone(tail.deref().borrow().next.as_ref().unwrap());
            let front_data = (*front).borrow().data;
            if self.size == 1 {
                self.tail = None;
            } else {
                (*tail).borrow_mut().next = Some(Rc::clone(&((*front).borrow().next.as_ref().unwrap())));
            }
            Some(front_data)
        }
    }

    pub fn peek(&self) -> Option<T> {
        if self.is_empty() {
            None
        } else {
            let tail = Rc::clone(self.tail.as_ref().unwrap());
            let front = Rc::clone(tail.deref().borrow().next.as_ref().unwrap());
            let front_data = (*front).borrow().data;
            Some(front_data)
        }
    }

    pub fn len(&self) -> usize {
        self.size
    }

    pub fn is_empty(&self) -> bool {
        self.size == 0
    }
}