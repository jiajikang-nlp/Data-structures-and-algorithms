public class Solution {
    //Insert one char from stringstream
    // 利用一个数组，而且数组的下标就是该字符代表的整数
    int[] hashTabel = new int[256]; // //因为这个字符是由8位组成，所以这儿数组最大是256个
    StringBuffer buffer = new StringBuffer(); // 相比及StringBuider速度慢，但是线程安全
    public void Insert(char ch)
    {
        buffer.append(ch); // 添加字符-将指定的字符串追加到此字符序列。
        if(hashTabel[ch]==0){ // 如果不存在
            hashTabel[ch] = 1;// 个数设置为1
        }else{
            hashTabel[ch] = hashTabel[ch] + 1; // 如果存在，个数+1
        }
        
    }
  //return the first appearence once char in current stringstream
    public char FirstAppearingOnce()
    {
        char[] temp = buffer.toString().toCharArray(); // 先转换成字符串，然后在转换成字符数组
        for(char ch:temp){ // 创建一个字符遍历：遍历temp数组
            if(hashTabel[ch]==1){// 获取第一次出现个数为1的字符
                return ch;
            }
        }
        return '#';
    
    }
}