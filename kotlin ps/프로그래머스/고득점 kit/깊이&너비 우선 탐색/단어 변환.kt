import java.util.*

class Solution {

    val WordMap = mutableMapOf<String, Int>()
    val MakeMap = mutableMapOf<String, Int>()
    var Target = ""
    var IsPossible = false
    var Answer = 0

    data class WordData(
        var word: String,
        var changeCount: Int
    )

    fun bfs(beginStr: String) {

        val beginWord = WordData(beginStr, 0)
        var queue: Queue<WordData> = LinkedList<WordData>()
        queue.add(beginWord)

        while (!queue.isEmpty()) {
            var currentWordData = queue.poll()
            var currentWord = currentWordData.word
            var curretChangeCount = currentWordData.changeCount

            for (i in currentWord.indices) {

                for (j in 0..25) {

                    var strBuilder = StringBuilder(currentWord)
                    strBuilder.setCharAt(i, 'a' + j)

                    var checkStr = strBuilder.toString()

                    if (WordMap[checkStr] == 1) { // 변환 가능 목록에 있다면
                        if (MakeMap[checkStr] != 1) { // 처음 변환한 목록이라면
                            if (checkStr == Target) { // 타겟과 같다면
                                IsPossible = true
                                Answer = curretChangeCount + 1

                                return
                            }

                            MakeMap[checkStr] = 1 // 변환 방문 체크
                            queue.add(WordData(checkStr, curretChangeCount + 1)) // 변환 카운트 1증가 후 큐에 넣기

                        }
                    }

                }
            }

        }

    }


    fun solution(begin: String, target: String, words: Array<String>): Int {
        var answer = 0

        Target = target

        for (i in words.indices) WordMap[words[i]] = 1  // 변환 가능한 목록 Map에 등록

        bfs(begin)

        if (IsPossible) answer = Answer
        else answer = 0

        return answer
    }
}