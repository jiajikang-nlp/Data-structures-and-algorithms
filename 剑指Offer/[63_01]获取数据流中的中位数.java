import java.util.Comparator;
import java.util.PriorityQueue;
public class Solution {
    
    private int count = 0; // 数据流中的数据个数
    // 优先队列集合实现堆，默认实现的是小根堆
    private PriorityQueue<Integer> minHeap = new PriorityQueue<>(); //小顶堆，默认容量为11
    // 定义大根堆，更改比较方式
    private PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(15,new Comparator<Integer>(){
        public int compare(Integer o1,Integer o2){
            return o2-o1;//o1-o1 则是小根堆 
        }
    });

   /*
     ① 当获取到数据时，先判断最大堆是否为空？
     ② 若为空时，则将获取到的数据添加到最大堆中；
     ③ 若最大堆不为空时需要比较最大堆堆顶元素与获取到的元素的大小，若最大堆堆顶元素大，则将该元素添加至最大堆中；若新元素大，则需要判断最小堆的情况。
     ④ 若最小堆为空时，直接将该元素添加至最小堆中；若最小堆不为空，则需比较新元素与最小堆堆顶元素的大小；
	 ⑤ 若最小堆堆顶元素小于等于，则将该元素添加至最小堆中；反之，则将该元素添加至最大堆中。
	 ⑥ 添加完成后，需要根据两个堆的大小情况平衡两堆中的元素，使之相差不超过1。
	 获取中位数时，判断已获取的数据的长度，若为偶数则在两堆顶元素之间；若为基数，则中位数是元素较多的堆的堆顶，返回即可。
   */
    public void Insert(Integer num) {
        if((count & 1)==0){ // 偶数
            // 当数据总数为偶数时，新加入的元素，应当进入小根堆
            // （注意不是直接进入小根堆，而是经大根堆筛选后取大根堆中最大元素进入小根堆）
            // 1.新加入的元素先入到大根堆，由大根堆筛选出堆中最大的元素
            maxHeap.offer(num); // 插入
            int filteredMaxNum = maxHeap.poll(); // 队列头部元素
            // 2.筛选后的【大根堆中的最大元素】进入小根堆
            minHeap.offer(filteredMaxNum);
        }else{
            // 当数据总数为奇数时，新加入的元素，应当进入大根堆
            // （注意不是直接进入大根堆，而是经小根堆筛选后取小根堆中最大元素进入大根堆）
            // 1. 新加入的元素先入到小根堆，由小根堆筛选出堆中最小的元素
            minHeap.offer(num);
            int filteredMaxNum = minHeap.poll();
            // 2. 筛选后的【小根堆中最小的元素】进去到大根堆
            maxHeap.offer(filteredMaxNum);
        }
        count++;
    }

    public Double GetMedian() {
        //数目为偶数时，中位数为小根堆堆顶元素与大根堆堆顶元素和的一半
        if((count & 1 )==0){ // 偶数
            return new Double((minHeap.peek() + maxHeap.peek()))/2;
        }else{
            return new Double(minHeap.peek());
        }
    }


}