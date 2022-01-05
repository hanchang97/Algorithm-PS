import java.util.Scanner

fun main(args: Array<String>) {
    val sc: Scanner = Scanner(System.`in`)
    var testCase = sc.nextInt()

    var arr = List(10, {ArrayList<Int>()})

    arr[0].add(0)

    arr[1].add(1)

    arr[2].add(2)
    arr[2].add(4)
    arr[2].add(8)
    arr[2].add(6)

    arr[3].add(3)
    arr[3].add(9)
    arr[3].add(7)
    arr[3].add(1)

    arr[4].add(4)
    arr[4].add(6)

    arr[5].add(5)

    arr[6].add(6)

    arr[7].add(7)
    arr[7].add(9)
    arr[7].add(3)
    arr[7].add(1)

    arr[8].add(8)
    arr[8].add(4)
    arr[8].add(2)
    arr[8].add(6)

    arr[9].add(9)
    arr[9].add(1)

    for(count in 1..testCase){
        var a = sc.nextInt()  // 1~99
        var b = sc.nextInt()

        if(a % 10 == 0){
            println(10)
        }
        else {
            // a의 1의 자리수 구하기
            a = getFirst(a)

            var size = arr[a].size

            b = b % size
            if (b == 0)
                println(arr[a][arr[a].size - 1])
            else
                println(arr[a][b - 1])

        }
    }

}

fun getFirst(num: Int): Int{
    if(num < 10)
        return num
    else
        return num % 10
}