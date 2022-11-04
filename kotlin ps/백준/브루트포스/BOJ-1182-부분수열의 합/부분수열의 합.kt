fun main() = with(System.`in`.bufferedReader()) {
    val info = readLine().split(" ").map { it.toInt() }
    val N = info[0]
    val S = info[1]

    val numList = readLine().split(" ").map { it.toInt() }

    var answer = 0
    for(i in 1 until (1 shl N)) {
        var sum = 0
        for(j in 0 until N) {
            if(i and (1 shl j) >= 1) {
                sum += numList[j]
            }
        }
        if(sum == S)
            answer++
    }

    println(answer)
}