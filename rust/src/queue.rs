use std::rc::{Rc, Weak};
use std::cell::RefCell;

#[allow(dead_code)]
pub struct Node<T: Copy> {
    data: T,
    next: Option<Rc<RefCell<Node<T>>>>,
    prev: Option<Weak<RefCell<Node<T>>>>,
}

#[allow(dead_code)]
pub struct Queue<T: Copy> {
    head: Option<Rc<RefCell<Node<T>>>>,
    tail: Option<Rc<RefCell<Node<T>>>>,
    size: usize
}

#[allow(dead_code)]
impl<T: Copy> Queue<T> {
    pub fn new() -> Queue<T> {
        Queue::<T>{head: None, tail: None, size: 0}
    }

    fn new_node(v: T) -> Rc<RefCell<Node<T>>> {
        Rc::new(RefCell::new(Node::<T>{data: v, next: None, prev: None}))
    }

    pub fn push(&mut self, v:T) {
        let n = Queue::<T>::new_node(v);
        match self.tail.take() {
            None => {
                self.tail = Some(Rc::clone(&n));
                self.head = Some(n);
            },
            Some(old_tail) => {
                self.tail = Some(Rc::clone(&n));
                n.borrow_mut().prev =
                    Some(Rc::downgrade(&old_tail));
                old_tail.borrow_mut().next = Some(n);
            },
        }
        self.size = self.size + 1;
    }

    pub fn pop(&mut self) -> Option<T> {
        match self.head.take() {
            None => None,
            Some(head) => {
                self.size = self.size - 1;
                let mut temp = head.borrow_mut();
                match temp.next.take() {
                    None => {
                        let return_val = temp.data;
                        self.head = None;
                        self.tail = None;
                        return Some(return_val);
                    }
                    Some(head_next) => {
                        let return_val = temp.data;
                        self.head = Some(Rc::clone(&head_next));
                        head_next.borrow_mut().prev = None;
                        return Some(return_val);
                    }
                }
            }
        }
    }

    pub fn is_empty(&self) -> bool {
        match self.head {
            None => true,
            Some(_) => false
        }
    } 

    pub fn len(&self) -> usize {
        self.size
    }

    pub fn peek(&self) -> Option<T> {
        match self.head {
            None => None,
            Some(ref head) => {
                Some(head.as_ref().borrow().data)
            }
        }
    }
}