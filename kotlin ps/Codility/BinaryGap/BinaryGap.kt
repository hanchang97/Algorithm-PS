fun solution(N: Int): Int {
    return getMaxResult(getBinaryString(N))
}

fun getBinaryString(num: Int): String {
    var str = ""
    var n = num
    while (n > 0) {
        str += if (n % 2 == 0) '0' else '1'
        n /= 2
    }
    return str.reversed()
}

fun getMaxResult(str: String): Int {
    var cnt = 0
    var maxResult = 0
    str.forEachIndexed { index, c ->
        if (c == '1') {
            if (cnt != 0 && cnt > maxResult) {
                maxResult = cnt
                cnt = 0
            }
        } else {
            if (str[index - 1] == '1') {
                cnt = 1
            } else {
                cnt++
            }
        }
    }

    return maxResult
}