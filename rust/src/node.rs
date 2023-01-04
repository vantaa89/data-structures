#[allow(dead_code)]
pub struct Node<T: Copy> {
    pub data: Option<T>,
    pub next: Option<Box<Node<T>>>
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
        let next = self.next
        .as_ref()
        .expect("Index out of range");
        match i {
            0 => next.data,
            _ => next.get(i - 1)
        }
    }
}