module Main where

import System.IO
import Game
import Beauty

data Answer = Yes | No

instance Read Answer where
  readsPrec _ "y" = [(Yes, "")]
  readsPrec _ "n" = [(No, "")]
  readsPrec _  _  = []

ask :: (Read a) => String -> IO a
ask question = do
  question |> toConsoleLn
  answer   <- fromConsoleLn

  return <| parsed answer

loop :: IO ()
loop = do
  player <- ask "Pick weapon: "
  ai     <- ask "Pick weapon: "

  player `vs` ai
    |> asText
    |> toConsoleLn

  answer <- ask "Wanna repeat? (y/n)"
  continueWith answer

end :: IO ()
end = "Finish!" |> toConsoleLn

continueWith :: Answer -> IO ()
continueWith Yes = loop
continueWith No  = end

main :: IO ()
main = do
  hSetBuffering stdout NoBuffering

  loop
