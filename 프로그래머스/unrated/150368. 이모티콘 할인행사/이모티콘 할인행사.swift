import Foundation

var array = [Int]()
var maxPlustCount = 0
var maxSalePrice = 0
let salePercent = [10,20,30,40]

func nextPermutation(cur: Int, users: [[Int]], emoticons: [Int]) {
    if array.count == emoticons.count {
        var plusCount = 0
        var salePrice = 0
        users.forEach {
            let userSale = $0[0]
            let userMaximum = $0[1]
            let tempArray = array.map { $0 < userSale ? 100 : $0 }
            
            let saleEmoticons = emoticons.enumerated().map { (idx, i) in
                i * (100 - tempArray[idx]) / 100
            }
            
            let sum = saleEmoticons.reduce(0,+)
            if sum >= userMaximum {
                plusCount += 1
            } else {
                salePrice += sum
            }
        }
        
        if maxPlustCount < plusCount {
            maxPlustCount = plusCount
            maxSalePrice = salePrice
        } else if maxPlustCount == plusCount && maxSalePrice < salePrice {
            maxSalePrice = salePrice
        }
    } else {
        for i in 0...3 {
            array.append(salePercent[i])
            nextPermutation(cur: i, users: users, emoticons: emoticons)
            array.removeLast()
        }
    }
}

func solution(_ users:[[Int]], _ emoticons:[Int]) -> [Int] {
    nextPermutation(cur: 0, users: users, emoticons: emoticons)
    return [maxPlustCount, maxSalePrice]
}