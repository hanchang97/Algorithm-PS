class Solution {

    val infoMap = mutableMapOf<String, ArrayList<String>>()
    val checkMap = mutableMapOf<Pair<String, String>, Int>()
    val wayList = ArrayList<String>()
    var isEnd = false

    fun solution(tickets: Array<Array<String>>): Array<String> {
        var answer = arrayOf<String>()

        tickets.forEach {
            val start = it[0]
            val end = it[1]

            if (infoMap[start] == null) {
                infoMap[start] = ArrayList<String>()
            }
            infoMap[start]?.let {
                it.add(end)
            }

            if (checkMap[Pair(start, end)] == null) {
                checkMap[Pair(start, end)] = 1
            } else {
                checkMap[Pair(start, end)] = checkMap[Pair(start, end)]!! + 1
            }
        }

        infoMap.forEach { key, value ->
            value.sort() // 알파벳 순서 앞서는 경로부터 탐색하기 위함
        }

        //println(infoMap)

        solve("ICN", "", tickets.size)

        wayList.sort()
        var ans = wayList[0].split(" ").toMutableList()
        ans.removeAt(0)
        answer = ans.toTypedArray()

        return answer
    }

    fun solve(dest: String, total: String, toChoose: Int) {
        if (toChoose == 0) {
            var tempTotal = total
            tempTotal += (" $dest")
            wayList.add(tempTotal)
            isEnd = true // 이미 정렬이 되어 있으므로 처음 찾은 경로가 가장 알파벳 순서 빠르다 / 추가 탐색 필요없다
            return
        }
        var tempTotal = total
        tempTotal += (" $dest")

        infoMap[dest]?.let { // null 체크 해주기!
            it.forEach { next ->
                if (checkMap[Pair(dest, next)]!! > 0) {
                    checkMap[Pair(dest, next)] = checkMap[Pair(dest, next)]!! - 1
                    solve(next, tempTotal, toChoose - 1)

                    if (isEnd) return

                    checkMap[Pair(dest, next)] = checkMap[Pair(dest, next)]!! + 1
                }
            }
        }
    }
}