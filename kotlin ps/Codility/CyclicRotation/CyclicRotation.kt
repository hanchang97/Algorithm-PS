fun solution(A: IntArray, K: Int): IntArray {

    if(A.size == 0)
        return intArrayOf()

    val moveCount = K % A.size
    val size = A.size
    val resultList = mutableListOf<Int>()

    ((size - moveCount) until size).forEach{
        resultList.add(A[it])
    }

    (0 until size - moveCount).forEach{
        resultList.add(A[it])
    }

    return resultList.toIntArray()
}