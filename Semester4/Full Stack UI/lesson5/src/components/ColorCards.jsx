import React, {useState} from "react";
import './ColorCards.css';

const ColorCards = ({ name, removeItem, index }) => {
      const [mode, setMode] = useState("");

      return(
      <div className={`container ${mode}`}>
            <div className="row">
                  <h1>Card</h1>
                  <button onClick={() => {removeItem(index)}}>X</button>
            </div>
            <div className="row">
                  <h2>{name}</h2>
            </div>
            <div className="row">
                  <button className="change" onClick={()=>setMode('red')} >red</button>
                  <button className="change" onClick={()=>setMode('green')}>green</button>
                  <button className="change" onClick={()=>setMode('blue')}>blue</button>
            </div>
      </div>
)};

export default ColorCards;