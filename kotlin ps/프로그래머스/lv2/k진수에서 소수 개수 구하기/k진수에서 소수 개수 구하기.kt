class Solution {
    fun solution(n: Int, k: Int): Int {
        var answer = check(convert(n, k))
        return answer
    }

    fun convert(n: Int, k: Int): String {
        var str = ""
        var num = n

        while (num > 0) {
            val r = num % k
            str += r.toString()
            num /= k
        }

        return str.reversed()
    }

    fun check(str: String): Int {
        var cnt = 0
        var nList = str.split('0')
        nList.forEach {
            if (it.isNotEmpty()) {
                if (checkPrime(it.toLong())) cnt++
            }
        }
        return cnt
    }

    fun checkPrime(n: Long): Boolean {
        if (n <= 1) return false
        var isPrime = true

        var i = 2L // 그냥 2로 하면 int 범위 내에서 밖에 계산을 못해서 시간초과 발생
        while (i * i <= n) {
            if (n % i == 0L) {
                isPrime = false
                break
            }
            i++
        }
        // for(i in 2..Math.sqrt(n.toDouble()).toLong()) { // 안전한 방식
        //     if(n % i == 0L){
        //         isPrime = false
        //         break
        //     }
        // }
        return isPrime
    }
}