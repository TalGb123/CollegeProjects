import { useState, useRef } from "react";
import Card from "./ColorCards.jsx";
import './Page.css';

const Page = () => {
      const [list, setList] = useState(["1", "2", "3", "4", "5"]);
      const name = useRef("");

      const add = () => {
            setList([...list, name.current]);
      }

      const removeItem = (index) => {
            const newList = list.filter((item, i) => i !== index);
            setList(newList);
      }
      
      return(
            <div className="container">
                  <div className="type">
                        <input type="text" placeholder="enter name" onChange={(e)=>{
                              name.current = e.target.value
                              console.log(name.current)
                        }}/>
                        <button onClick={add}>+</button>
                  </div>
                  <div className="gallery">
                        {list.map((item,index)=><Card name={item} removeItem={removeItem} index={index}/>)}
                  </div>
            </div>
      )
}

export default Page;