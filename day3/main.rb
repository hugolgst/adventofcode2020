lines = File.open('entry.txt').readlines.map(&:chomp)

slopes = [
  { right: 1, down: 1 },
  { right: 3, down: 1 },
  { right: 5, down: 1 },
  { right: 7, down: 1 },
  { right: 1, down: 2 }
]

result = [0]*slopes.size
slopes.each_with_index do |slope, slopeIndex|
  index = 0

  lines.each_with_index do |line, i|
    # Pass lines between the current and the next position
    next unless i%slope[:down] == 0

    # Get the current character and repeat the string if not enough long
    character = (line*(index/line.size+1))[index]
    result[slopeIndex] += 1 if character == ?#
    # Move to the right following the current slope
    index += slope[:right]
  end
end

puts result, "", result.reduce(:*)