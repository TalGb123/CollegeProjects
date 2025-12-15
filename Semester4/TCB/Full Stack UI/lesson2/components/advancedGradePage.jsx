import React from "react";
import './advancedGradePage.css';
const AdvancedGradePage = (props) =>
{
      const { grade, subject, description1, description2 } = props;
      return (<div>
            <div className="flex-vertical">
                  <h2>subject: {subject}</h2>
                  <h2>grade: {grade}</h2>
            </div>
            <div className="flex-horizontal">
                  <p>{description1}</p>
                  <p>{description2}</p>
            </div>
            <div>
                  <div className="buttons">
                        <button>Appeal</button>
                        <button>Submit</button>
                  </div>
                  <div className="">signature</div>
            </div>
      </div>)
}
export default AdvancedGradePage