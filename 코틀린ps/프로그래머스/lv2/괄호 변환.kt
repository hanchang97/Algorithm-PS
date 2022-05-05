import java.util.*    // 스택 자료구조 사용 위함

class Solution {

    fun divide(p: String): String {

        if (p == "") return ""  // 빈 문자열이면 바로 빈 문자열 리턴

        var u = ""
        var v = ""

        var openCount = 0
        var closeCount = 0

        run {  // 최초로 (, ) 개수 같아지는 순간 = u 완성
            p.forEach {
                if (it == '(') openCount++
                else closeCount++

                u += it
                if (openCount == closeCount) return@run
            }
        }

        if (p.length > u.length) { // v 완성하기 , u를 뺀 나머지
            for (i in u.length..p.length - 1) {
                v += p[i]
            }
        }


        val strStack = Stack<Char>()  // u가 올바른 괄호 문자열 인지 검사하기 위한 스택
        u.forEach {
            if (it == '(') strStack.push(it)
            else {
                if (strStack.size > 0 && strStack.peek() == '(') strStack.pop()
                else strStack.push(it)
            }
        }

        if (strStack.size == 0) { // u가 올바른 괄호 문자열
            return u + divide(v)   // 재귀
        } else {
            // ( + v수행 + ) + u앞뒤 제거
            var cutU = ""
            var changeCutU = ""
            if (u.length > 2) {  // u 길이가 2이하 이면 앞뒤 자른 경우 무조건 빈 문자열!
                cutU = u.substring(1, u.length - 1)

                cutU.forEach { // 자른 후 괄호 방향 뒤집기
                    if (it == '(') changeCutU += ")"
                    else changeCutU += "("
                }
            }

            return "(" + divide(v) + ")" + changeCutU
        }

    }

    fun solution(p: String): String {
        var answer = ""

        val strStack = Stack<Char>()

        p.forEach { // p가 애초에 올바른 괄호 문자열 인지 체크
            if (it == '(') strStack.push(it)
            else {
                if (strStack.size > 0 && strStack.peek() == '(') strStack.pop()
                else strStack.push(it)
            }
        }

        if (strStack.size == 0) return p

        answer = divide(p)

        return answer
    }
}