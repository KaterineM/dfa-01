require 'set'

def generate_array x
  len = 2*x
  array1 = *(1..x)
  array2 = Array.new(x) { rand(1...x) }
  array = array1+array2
  array = array.shuffle
  File.open('array_for_matrix', 'w') do |f|
    array.each { |element| f.puts(element) }
  end
end

generate_array(ARGV[0].to_i)
