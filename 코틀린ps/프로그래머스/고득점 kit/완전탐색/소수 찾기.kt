import kotlin.math.sqrt

class Solution {

    var N = 0
    var Answer = 0
    var Numbers = ""
    lateinit var isUsed: IntArray

    val PrimeMap = mutableMapOf<Int, Int>()  // 중복 방지용

    fun checkPrime(number: String): Boolean {
        val n = number.toInt()

        if (n <= 1) return false
        if (PrimeMap[n] != null) return false  // 이미 찾은 소수면 넘어간다

        for (i in 2..sqrt(n.toDouble()).toInt()) {
            if (n % i == 0) return false
        }

        PrimeMap[n] = 1
        return true

    }

    fun getResult(count: Int, currentStr: String) {

        if (count > N) { // 하나의 순열이 완성
            if (checkPrime(currentStr)) Answer++
        } else {
            for (i in 0..N - 1) {
                if (isUsed[i] == 0) {
                    isUsed[i] = 1
                    val checkStr = currentStr + Numbers[i]

                    if (checkPrime(checkStr)) Answer++
                    // 모든 수를 한 번씩 사용해서 순열을 만드는 과정에서 각 과정마다 소수인지 체크!!

                    getResult(count + 1, checkStr)
                    isUsed[i] = 0
                }
            }
        }

    }


    fun solution(numbers: String): Int {

        N = numbers.length
        isUsed = IntArray(N) { 0 }
        Numbers = numbers

        getResult(1, "")

        return Answer
    }
}