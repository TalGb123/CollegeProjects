import { useState, useRef } from "react";
import BMICard from "./BMICard.jsx";
import './BMICalc.css';

const BMICalc = () => {
      const [list, setList] = useState([]);
      const name = useRef("");
      const height = useRef("");
      const weight = useRef("");

      const add = () => {
            if (name.current && height.current && weight.current) {
                  setList([...list, {
                        name: name.current,
                        height: height.current,
                        weight: weight.current
                  }]);
                  name.current = "";
                  height.current = "";
                  weight.current = "";
            }
      }

      const removeItem = (index) => {
            const newList = list.filter((item, i) => i !== index);
            setList(newList);
      }

      return(
            <div className="container">
                  <div className="type">
                        <div className="row">
                              <button onClick={add}>+</button>
                              <div className="column">
                                    <h2>Height</h2>
                                    <input type="text" placeholder="height" onChange={(e)=>{
                                          height.current = e.target.value;
                                          console.log(height.current);
                                    }}/>
                              </div>
                              <div className="column">
                                    <h2>Weight</h2>
                                    <input type="text" placeholder="weight" onChange={(e)=>{
                                          weight.current = e.target.value;
                                          console.log(weight.current);
                                    }}/>
                              </div>
                              <div className="column">
                                    <h2>Name</h2>
                                    <input type="text" placeholder="name" onChange={(e)=>{
                                          name.current = e.target.value;
                                          console.log(name.current);
                                    }}/>
                              </div>
                        </div>
                  </div>
                  <div className="gallery">
                        {list.map((item, index) => (
                              <BMICard 
                                    key={index} 
                                    height={item.height} 
                                    weight={item.weight} 
                                    name={item.name} 
                                    removeItem={removeItem} 
                                    index={index}
                              />
                        ))}
                  </div>
            </div>
      )
};
export default BMICalc;