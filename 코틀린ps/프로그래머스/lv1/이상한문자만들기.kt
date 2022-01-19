class Solution {
    fun solution(s: String): String {
        var answer = ""
        var input = s

        var resultStr = ""
        var count = 0

        for(i in 0..input.length-1){
            var ascii = input[i].toInt()
            if(ascii != 32){
                if(count % 2 == 0){ //짝수 -> 대문자
                    if(ascii >= 97) ascii -= 32
                    resultStr += ascii.toChar()
                }
                else{ // 홀수 -> 소문자
                    if(ascii < 97) ascii += 32
                    resultStr += ascii.toChar()
                }
                count++
            }
            else{
                resultStr += " "
                count = 0
            }
        }

        return resultStr
    }
}