#[path ="../src/node.rs"] mod node;
use std::borrow::BorrowMut;

use node::*;

#[allow(dead_code)]
pub struct Queue<T: Copy> {
    tail: Option<Box<Node<T>>>,
    size: usize,
}

#[allow(dead_code)]
impl<T: Copy> Queue<T> {
    pub fn new() -> Queue::<T> {
        Queue::<T> {tail: None, size:0}
    }

    pub fn enqueue(&mut self, data: T) {
        let new_node = Node::<T>{data: Some(data), next: None};
        match self.tail {
            Some(_) => {
                let mut head = self.tail.as_mut().unwrap().as_mut();
                loop {  // inefficiency (O(n))
                    match head.next {
                        Some(_) => {
                            head = head
                            .next.as_mut()
                            .unwrap()
                            .as_mut();
                        },
                        None => break
                    }
                }
                head.next = Some(Box::new(new_node));
            },
            None => {
                self.tail = Some(Box::new(new_node));
            }
        }
        self.size = self.size + 1;
    }

    pub fn dequeue(&mut self) -> Option<T> {
        if let Some(_) = self.tail {
            let mut tail = self.tail.take().unwrap();
            self.tail = tail.next;
            self.size = self.size - 1;    
            tail.data
        } else {
            None
        }
    }

    pub fn len(&self) -> usize {
        self.size
    }

    pub fn peek(&mut self) -> Option<T> {
        if let Some(_) = self.tail {
            self.tail.as_mut().unwrap().data
        } else {
            None
        }
    }
}