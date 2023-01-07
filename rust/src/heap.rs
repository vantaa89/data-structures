const MAX_N: usize = 100000;

#[allow(dead_code)]
pub struct MinHeap<T: PartialOrd + Copy> {
    data: [Option<T>;MAX_N],
    size: usize
}

#[allow(dead_code)]
impl<T: PartialOrd + Copy> MinHeap<T> {
    pub fn new() -> MinHeap<T> {
        MinHeap::<T> { data: [None;MAX_N], size: 0 }
    }

    pub fn push(&mut self, elem: T) {
        self.data[self.size] = Some(elem);
        let mut pivot = self.size;
        self.size = self.size + 1;
        while pivot > 0 {
            let parent = (pivot - 1) / 2;   // index of the parent node
            if self.data[pivot] < self.data[parent] {
                self.data.swap(pivot, parent); // swap method on slices
                pivot = parent;
            }
            else {
                break;
            }
        }
    }

    pub fn pop(&mut self) -> Option<T> {
        let ret = self.data[0];    // the value to be popped
        self.data.swap(self.size-1, 0);
        self.size = self.size - 1;      // decrement the size of the heap
        self.data[self.size] = None;
        let mut pivot = 0;
        while pivot < self.size {
            let (left, right) = (2*pivot+1, 2*pivot+2);
            if left < self.size && right < self.size{
                // pivot has both left and right child
                if self.data[left] <= self.data[right] && self.data[left] < self.data[pivot] {
                    self.data.swap(left, pivot);
                    pivot = left;
                }
                else if self.data[left] > self.data[right] && self.data[right] < self.data[pivot] {
                    self.data.swap(right, pivot);
                    pivot = right;
                }
                else {
                    break
                }
            }
            else if self.size == right { // the pivot has only left child
                if  self.data[left] < self.data[pivot] {
                    self.data.swap(left, pivot);
                    pivot = left;
                }
                else {
                    break
                }
            }
            else {
                break;
            }
        }
        ret // Copy bound for generic T is required because of this
    }
}