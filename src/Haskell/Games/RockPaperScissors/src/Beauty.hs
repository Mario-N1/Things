module Beauty where

toConsole :: String -> IO ()
toConsole = putStr

toConsoleLn :: String -> IO ()
toConsoleLn = putStrLn

fromConsole :: IO String
fromConsole = getLine

fromConsoleLn :: IO String
fromConsoleLn = getLine

asText :: Show a => a -> String
asText = show

parsed :: Read a => String -> a
parsed = read

infixl 7 `as`
x `as` f = f x

infixl 7 |>
x |> f = f x
