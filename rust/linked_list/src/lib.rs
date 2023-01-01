mod linked_list;

pub fn add(left: usize, right: usize) -> usize {
    left + right
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn it_works() {
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
}
