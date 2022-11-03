class Solution {
    fun solution(fees: IntArray, records: Array<String>): IntArray {
        var answer: IntArray = intArrayOf()

        val baseTime = fees[0]
        val baseFee = fees[1]
        val addTime = fees[2]
        val addFee = fees[3]

        val pMap = mutableMapOf<String, Int>() // 입/출차 정보
        val tMap = mutableMapOf<String, Int>() // 총 주차시간 정보

        records.forEach {
            val infoList = it.split(" ")
            //println(infoList)

            val car = infoList[1]

            val timeList = infoList[0].split(":")
            val hour = timeList[0].toInt()
            val minute = timeList[1].toInt()
            val time = hour * 60 + minute

            if (pMap[car] == null || pMap[car] == -1) { // 입차 대상
                pMap[car] = time
            } else { // 출차 대상
                val inTime = pMap[car]
                pMap[car] = -1
                val pTime = time - inTime!!

                if (tMap[car] == null) {
                    tMap[car] = pTime
                } else {
                    tMap[car] = tMap[car]!! + pTime
                }
            }
        }

        // 입차 상태 남았는지 확인하기
        pMap.forEach { key, value ->
            if (value >= 0) {
                val pTime = (23 * 60 + 59) - value

                if (tMap[key] == null) {
                    tMap[key] = pTime
                } else {
                    tMap[key] = tMap[key]!! + pTime
                }
            }
        }

        //println(tMap)

        val feeList = ArrayList<Pair<String, Int>>()
        tMap.forEach { key, value ->
            var fee = baseFee
            var pTime = value
            pTime -= baseTime

            if (pTime > 0) {
                val uTime = if (pTime % addTime == 0) pTime / addTime else pTime / addTime + 1
                fee += uTime * addFee
            }
            feeList.add(Pair(key, fee))
        }

        answer = feeList.sortedWith(compareBy<Pair<String, Int>> { it.first }).map {
            it.second
        }.toIntArray()

        return answer
    }
}