fun main() = with(System.`in`.bufferedReader()) {
    var (N, K) = readLine().split(' ').map { it.toInt() }

    val coins = Array(N) { readLine().toInt() }

    val table = IntArray(K + 1) { 0 }
    table[0] = 1

    coins.forEach { coin ->
        (coin..K).forEach {
            table[it] += table[it - coin]
        }
    }
    // 현재 검사하려는 코인만 보므로 중복 피하게 된다

    println(table[K])
}