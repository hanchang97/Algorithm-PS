class Solution {

    var Size = 0
    var Count = 0
    var Target = 0


    fun getResult(currentSum: Int, currentIndex: Int, numbers: IntArray){
        if(currentIndex == Size){
            if(currentSum == Target) Count++
        }
        else{
            getResult(currentSum - numbers[currentIndex], currentIndex + 1, numbers)
            getResult(currentSum + numbers[currentIndex], currentIndex + 1, numbers)
        }
    }

    fun solution(numbers: IntArray, target: Int): Int {

        Size = numbers.size
        Target = target

        getResult(0, 0, numbers)

        return Count
    }
}