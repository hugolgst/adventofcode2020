const fs = require('fs')

const data = fs.readFileSync('entry.txt', 'utf8')
const passports = data.split("\n\n")
const neccesaryTags = [
  'byr',
  'iyr',
  'eyr',
  'hgt',
  'hcl',
  'ecl',
  'pid'
]

let count = 0
for (let passport of passports) {
  let valid = true
  for (let tag of neccesaryTags) {
    if (!passport.includes(tag)) {
      valid = false
      break
    }
  }

  if (valid) count++
}

console.log(count)