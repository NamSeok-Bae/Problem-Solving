import Foundation

func solution(_ dartResult:String) -> Int {
    var array = [0]
    var text = ""
    for i in dartResult {
        if ["S","D","T"].contains(i) {
            array.append(Int(text)!)
            text = ""
            var multy = 0
            switch i {
            case "S":
                multy = 1
            case "D":
                multy = 2
            case "T":
                multy = 3
            default:
                break
            }
            array[array.count-1] = Int(pow(Double(array[array.count-1]), Double(multy)))
        } else if ["*", "#"].contains(i) {
            switch i {
            case "*":
                array[array.count-1] *= 2
                array[array.count-2] *= 2
            case "#":
                array[array.count-1] *= -1
            default:
                break
            }
        } else {
            text.append(i)
        }
    }

    return array.reduce(0,+)
}