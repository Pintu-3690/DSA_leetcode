/**
 * @param {string} s
 * @return {boolean}
 */
var checkString = function(s) {
    let seenB = false;

    for (let i = 0; i < s.length; i++) {
        if (s[i] === "b") {
            seenB = true;
        } else if (seenB) {
            
            return false;
        }
    }

    return true;
};