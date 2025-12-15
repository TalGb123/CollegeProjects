import { useEffect, useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  const [count, setCount] = useState(0);
  useEffect(() => {
    console.log("number is changed:", count);
    if (count % 7 === 0 && count !== 0) {
      alert("BOOM!");
    }
  }, [count]);

  return (
    <>
    <div>
      <h1> 7 boom game</h1>
    </div>
    <div>
      <button onClick={() => {
        setCount(count+1);
      }}>Click</button> 
      <p>{count}</p> 
    </div>  
    </>
  )
}

export default App
