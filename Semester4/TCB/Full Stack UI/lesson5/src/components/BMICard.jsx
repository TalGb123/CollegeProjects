import react, {useState} from "react";
import './BMICalc.css';

const BMICard = ({height, weight, name, removeItem, index}) => {
      
      const calculateBMI = () => {
            if (height >= 10) {
                  var height1 = height / 100;
            }
            const bmi = weight / (height1 * height1);
            return bmi.toFixed(2);
      }

      return(
            <div className="container">
                  <div className="row">
                        <button onClick={() => {removeItem(index)}}>X</button>
                        <div className="column">
                              <h2>BMI</h2>
                              <h3>{calculateBMI()}</h3>
                        </div>
                        <div className="column">
                              <h2>Name</h2>
                              <h3>{name}</h3>
                        </div>
                  </div>
            </div>
      )

};
export default BMICard;