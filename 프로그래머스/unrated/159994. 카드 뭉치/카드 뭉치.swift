import Foundation

func solution(_ cards1:[String], _ cards2:[String], _ goal:[String]) -> String {
    var reversed_cards1 = Array(cards1.reversed())
    var reversed_cards2 = Array(cards2.reversed())
    var result = [String]()

    for i in goal {
        if i == reversed_cards1.last {
            result.append(reversed_cards1.removeLast())
        }
        if i == reversed_cards2.last {
            result.append(reversed_cards2.removeLast())
        }
    }

    return result != goal ? "No" : "Yes"
}