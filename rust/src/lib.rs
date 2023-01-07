mod linked_list;
mod queue;
mod stack;

pub fn add(left: usize, right: usize) -> usize {
    left + right
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn linked_list() {
        let mut list = linked_list::LinkedList::<i32>::new();
        list.append(3);
        list.append(6);
        list.append(7);
        assert_eq!(list.get(0).unwrap(), 3);
        assert_eq!(list.get(1).unwrap(), 6);
        assert_eq!(list.get(2).unwrap(), 7);
        assert_eq!(list.len(), 3);
        list.add(1, 9);
        assert_eq!(list.get(0).unwrap(), 3);
        assert_eq!(list.get(1).unwrap(), 9);
        assert_eq!(list.get(2).unwrap(), 6);
        assert_eq!(list.get(3).unwrap(), 7);
        assert_eq!(list.len(), 4);
        list.remove(2);
        assert_eq!(list.get(0).unwrap(), 3);
        assert_eq!(list.get(1).unwrap(), 9);
        assert_eq!(list.get(2).unwrap(), 7);
        assert_eq!(list.len(), 3);
        assert_eq!(list.is_empty(), false)
    }

    #[test]
    fn stack() {
        let mut stack = stack::Stack::<i32>::new();
        let arr = [1, 3, 7, -1, 6, 10, -1, 4, 3, -1, 5];
        for i in 0..11 {
            match arr[i] {
                -1 => {
                    let a = stack.pop();
                    assert_eq!(a, arr[i-1])
                },
                _ => {
                    stack.push(arr[i]);  
                }
            }
        }
        assert_eq!(stack.len(), 5);
        for _ in 0..5 {
            assert_ne!(stack.len(), 0);
            let a = stack.peek();
            assert_eq!(stack.pop(), a);
        }
    }
    #[test]
    fn queue() {
        let mut queue = queue::DLList::<i32>::new();
        let arr = [1, 3, -1, 7, 6, 10, -1, 4, 3, -1, 5, -1, -1, -1, -1, -1];
        let out = [1, 3, 7, 6, 10, 4, 3, 5];
        let mut cnt = 0;
        for i in 0..16 {
            match arr[i] {
                -1 => {
                    let a = queue.pop().unwrap();
                    assert_eq!(a, out[cnt]);
                    cnt = cnt + 1;
                },
                _ => {
                    queue.push(arr[i]);  
                }
            }
        }
        for _ in 0..5 {
            assert_ne!(queue.is_empty(), false);
            let a = queue.peek();
            assert_eq!(queue.pop(), a);
        }
    }
}
