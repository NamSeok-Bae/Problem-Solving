import Foundation

func solution(_ s:String, _ skip:String, _ index:Int) -> String {
    var alphabet = Array("abcdefghijklmnopqrstuvwxyz").map { String($0) }.filter { alpha in
    !Array(skip).contains(Character(alpha))
}

var result = ""
for i in s {
    let idx = alphabet.firstIndex(of: String(i))!
    
    var newIndex = idx + index
    while newIndex >= 26 - skip.count {
        newIndex -= (26-skip.count)
    }
    result.append(alphabet[newIndex])
}
    
    return result
}