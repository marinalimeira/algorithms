# Given a set of items, each with a weight and a value, determine the number of
# each item to include in a collection so that the total weight is less than or
# equal to a given limit and the total value is as large as possible.
#
# https://en.wikipedia.org/wiki/Knapsack_problem
#
# $ ruby knapsack.rb

class Knapsack
  def initialize()
    args       = to_arri gets
    @list_size = args[0]      # number of items
    @storage   = args[1]      # knapsack storage
    @values    = to_arri gets # array containing items values
    @weights   = to_arri gets # array containing items weights
    @memo      = Array.new(@list_size + 1){ Array.new(@storage + 1) }

    puts dp 0, @storage
  end

  def dp i, max_w
    return @memo[i][max_w] if @memo[i][max_w]

    @memo[i][max_w] = if i.eql? @list_size || max_w.eql?(0)
                        0
                      elsif @weights[i] > max_w
                        dp i + 1, max_w
                      else
                        [@values[i] + dp(i + 1, max_w - @weights[i]),
                         dp(i + 1, max_w)].max
                      end
  end

  private

  def to_arri string
    string.scan(/[0-9]+/).map { |i| i.to_i }
  end
end

Knapsack.new
