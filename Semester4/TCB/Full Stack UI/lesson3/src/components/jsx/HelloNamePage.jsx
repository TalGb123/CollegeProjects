import React from "react";
import { useState } from "react";
import "../css/HelloNamePage.css";

const HelloNamePage = () => {
      const [name, setName] = useState("");
      const [list, setList] = useState([]);

      const addName = () => {
            if (name.trim()) {
                  setList([...list, name]);
                  setName(""); // Clear input after adding
            }
      }

      const removeItem = (index) => {
            const newList = list.filter((_, i) => i !== index);
            setList(newList);
      }

      return(
            <div>
                  <div className="row">
                        <button onClick={addName}>+</button>
                        <input 
                              placeholder="Enter Name" 
                              value={name}
                              onChange={(e) => setName(e.target.value)}
                        />
                  </div>
                  <div className="name-list">
                        {list.map((item, index) => (        
                              <div className="row" key={index}>
                                    <span>{item}</span>
                                    <button onClick={() => removeItem(index)}>Remove</button>
                              </div>
                        ))}
                  </div>
            </div>
      );
};

export default HelloNamePage;