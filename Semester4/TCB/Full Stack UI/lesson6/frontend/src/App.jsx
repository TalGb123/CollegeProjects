import { useRef, useState } from 'react'
import './App.css'
import { useEffect } from 'react'
import axios from 'axios'
function App() {

  const search = useRef(1)
  const [user,setUser] = useState({
    id: '',
    name: '',
    email: '',
  })

  return (
    <div className='container'>
      <div className='row'>
        <button onClick={()=>axios.get(`http://localhost:3000/user/${search.current}`).then((res)=>{
          setUser(res.data);
          console.log(res.data);
        })}>+</button>
        <input type='text' onChange={(e)=>search.current=e.target.value}/>
      </div>
      <div>
        <h3>Id:{user.id}</h3>
        <h3>Name:{user.name}</h3>
        <h3>Email:{user.email}</h3>
      </div>
    </div>
  )
}

export default App
