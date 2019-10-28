module Main where

import Game

main :: IO ()
main = do
  putStrLn $ show $ win "Paper" "Scissors"
