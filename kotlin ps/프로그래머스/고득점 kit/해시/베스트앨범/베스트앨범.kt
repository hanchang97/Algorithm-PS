class Solution {
    fun solution(genres: Array<String>, plays: IntArray): IntArray {

        var mapGenre = mutableMapOf<String, Int>()

        for (i in 0..genres.size - 1) { // map 최초로 들어오는 key null check
            if (mapGenre[genres[i]] == null) mapGenre[genres[i]] = 0
            mapGenre[genres[i]] = mapGenre[genres[i]]!! + plays[i]
        }

        val listGenre = mapGenre.toList().sortedWith(compareByDescending { it.second })
        // sortedWith = 새로운 리스트 반환

        for (i in listGenre.indices) mapGenre[listGenre[i].first] = i

        val arr2 = Array(mapGenre.size) { ArrayList<Pair<Int, Int>>() } // <inx, value>
        // c++ 과 다르게 kotlin은 변수로 배열 사이즈 초기화 가능

        for (i in 0..genres.size - 1) {
            val inx = mapGenre[genres[i]]
            arr2[inx!!].add(Pair(i, plays[i]))  // Pair 추가 시 'Pair(first, second)' 형태!
        }


        for (i in 0..arr2.size - 1) arr2[i].sortByDescending { it.second }
        // 각 행(장르) 별로 정렬 수행

        val tempArrayList = arrayListOf<Int>()
        for (i in 0..arr2.size - 1) {
            tempArrayList.add(arr2[i][0].first)
            if (arr2[i].size >= 2) tempArrayList.add(arr2[i][1].first)
        }

        var answer = tempArrayList.toIntArray()  // ArrayList -> IntArray

        return answer
    }
}