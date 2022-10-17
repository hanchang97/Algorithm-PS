data class Info(
    val genre: String,
    val play: Int,
    val inx : Int
)

class Solution {
    fun solution(genres: Array<String>, plays: IntArray): IntArray {
        var answer = mutableListOf<Int>()

        val infoList = ArrayList<Info>()

        genres.forEachIndexed{inx, value ->
            infoList.add(Info(value, plays[inx], inx))
        }

        val infoMap = infoList.groupBy { it.genre }
        val ifl = infoMap.toList().sortedWith(compareBy { it.second.sumOf { -1 * it.play} }) // 총합 내림차순

        val resultList = mutableListOf<Info>()
        ifl.forEach {
            it.second.sortedWith(compareBy<Info> { -1 * it.play }.thenBy {it.inx}).take(2).forEach {
                resultList.add(it)
            }
            // 한 장르안에서 플레이수 내림차순, 인덱스 오름차순 & 앞에서 최대 2개만
        }

        resultList.forEach{
            answer.add(it.inx)
        }

        return answer.toIntArray()
    }
}