#[allow(dead_code)]
struct Node<T: Copy> {
    data: Option<T>,
    next: Option<Box<Node<T>>>
}

#[allow(dead_code)]
impl<T: Copy> Node<T> {
    pub fn new(data: T) -> Node<T> {
        Node::<T> {data: Some(data), next: None}
    }

    pub fn add(&mut self, i: usize, data: T) {
        if i == 0 {
             let new_node = Node {data: Some(data), next: self.next.take()};
             self.next = Some(Box::new(new_node));
        } else {
            self.next.as_mut().expect("Index out of range").add(i-1, data);
        }
    }

    pub fn append(&mut self, data: T){
        match self.next {
            None => {
                let new_node = Node {data: Some(data), next: None};
                self.next = Some(Box::new(new_node))
            }
            Some(ref mut next) => {
                next.append(data);
            }
        }
    }

    pub fn remove(&mut self, i: usize) -> Option<T> {
        if i == 0 {
            let next = self.next.take().expect("Index out of range");
            let ret = next.data;
            self.next = next.next; // link to up next
            ret
        } else{
            self.next.as_mut().unwrap().remove(i-1)
        }
    }
    pub fn get(& self, i: usize) -> Option<T> {
        let next = self.next.as_ref().expect("Index out of range");
        match i {
            0 => next.data,
            _ => next.get(i - 1)
        }
    }
}

#[allow(dead_code)]
pub struct LinkedList<T: Copy> {
    head: Box<Node<T>>,
    size: usize
}

#[allow(dead_code)]
impl<T: Copy> LinkedList<T> {
    pub fn new() -> LinkedList<T> {
        LinkedList::<T> { head: Box::new(Node{data:None, next: None}), size: 0 }
    }
    pub fn add(&mut self, i: usize, data: T) -> bool {
        if i > self.size {
            false   // Index out of range
        } else {
            self.head.add(i, data);
            self.size = self.size + 1;
            true
        }
    }
    pub fn append(&mut self, data: T){
        self.head.append(data);
        self.size = self.size + 1;
    }
    pub fn remove(&mut self, i: usize) -> Option<T> {
        if i >= self.size {
            None    // Index out of range
        } else {
            self.size = self.size - 1;
            self.head.remove(i)
        }
    }
    pub fn get(&mut self, i: usize) -> Option<T> {
        self.head.get(i)
    }
    pub fn len(&mut self) -> usize {
        self.size
    }
    pub fn is_empty(&mut self) -> bool {
        self.size == 0
    }
}

