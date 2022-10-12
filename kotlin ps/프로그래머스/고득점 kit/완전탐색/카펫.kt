class Solution {
    fun solution(brown: Int, yellow: Int): IntArray {
        var answer = intArrayOf(0,0)

        var height = 3 // 최소 가능 높이는 3
        var width = brown/2 - (height - 2)

        while(width >= height){
            if((width-2) * (height-2) == yellow){
                answer[0] = width
                answer[1] = height

                break
            }

            height++
            width = brown/2 - (height - 2)
        }

        return answer
    }
}