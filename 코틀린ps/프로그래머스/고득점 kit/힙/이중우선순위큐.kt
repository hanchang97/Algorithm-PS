import java.util.*

class Solution {
    fun solution(operations: Array<String>): IntArray {
        var answer = intArrayOf(0, 0)

        var size = 0

        val minHeap = PriorityQueue<Int>(Comparator{int1, int2 ->
            when{
                int1 > int2 -> 1
                else -> -1
            }
        })

        val maxHeap = PriorityQueue<Int>(Comparator{int1, int2 ->
            when{
                int1 < int2 -> 1
                else -> -1
            }
        })

        for(i in 0..operations.size-1){
            val split = operations[i].split(' ')

            if(split[0] == "I"){
                size++
                minHeap.add(split[1].toInt())
                maxHeap.add(split[1].toInt())
            }
            else{
                if(size >= 1){
                    size--
                    if(split[1] == "1"){
                        maxHeap.poll()
                    }
                    else{
                        minHeap.poll()
                    }

                    if(size == 0){
                        maxHeap.clear()
                        minHeap.clear()
                    }
                }
            }

        }

        if(size != 0){  // 이 처리를 안해주려면 애초에 최소, 최대힙에서 remove를 통해 같이 제거해주는 방법도 가능할듯
            answer[0] = maxHeap.peek()
            answer[1] = minHeap.peek()
        }

        return answer
    }
}