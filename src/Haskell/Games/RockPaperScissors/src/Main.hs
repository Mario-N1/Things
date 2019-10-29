module Main where

import System.IO
import Game

data Answer = Yes | No

instance Read Answer where
  readsPrec _ "y" = [(Yes, "")]
  readsPrec _ "n" = [(No, "")]
  readsPrec _ _ = []

ask :: String -> IO Answer
ask question = do
  putStr question
  char <- getLine
  return $ read char

ioWeapon :: IO Weapon
ioWeapon = do
  putStr "Pick weapon: "
  line <- getLine
  return $ weaponOf line

end :: IO ()
end = putStrLn "Finish!"

loop :: IO ()
loop = do
  player <- ioWeapon
  ai     <- ioWeapon

  putStrLn $ show $ player `vs` ai

  answer <- ask "Wanna repeat? "
  continue answer

continue :: Answer -> IO ()
continue Yes = loop
continue No  = end

main :: IO ()
main = do
  hSetBuffering stdout NoBuffering

  loop
