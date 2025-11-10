import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
import App from './App.jsx'
import ToolPage from '../components/toolpage.jsx'
import GradePage from '../components/gradepage.jsx'
import AdvancedGradePage from '../components/advancedGradePage.jsx'


createRoot(document.getElementById('root')).render(
  <StrictMode>
    {/* <App />
    <ToolPage 
      name="ScrewDriver" 
      price="10$" 
      link="https://www.aliexpress.com/p/tesla-landing/index.html?scenario=c_ppc_item_bridge&productId=1005008722110390&_immersiveMode=true&withMainCard=true&src=google&aff_platform=true&isdl=y&src=google&albch=shopping&acnt=231-612-1468&isdl=y&slnk=&plac=&mtctp=&albbt=Google_7_shopping&aff_platform=google&aff_short_key=_oFgTQeV&gclsrc=aw.ds&&albagn=888888&&ds_e_adid=&ds_e_matchtype=&ds_e_device=c&ds_e_network=x&ds_e_product_group_id=&ds_e_product_id=he1005008722110390&ds_e_product_merchant_id=5568805770&ds_e_product_country=IL&ds_e_product_language=iw&ds_e_product_channel=online&ds_e_product_store_id=&ds_url_v=2&albcp=22967702820&albag=&isSmbAutoCall=false&needSmbHouyi=false&gad_source=4&gad_campaignid=22967705964&gbraid=0AAAABBR8kP0WRkKAeFpV7mqarFFTa4ugZ&gclid=CjwKCAjw04HIBhB8EiwA8jGNbeQ0N_nb8mzWROcL1jJtBNopKzi52ZIA6C8kn_ootteFzULD4ZFijRoC9VIQAvD_BwE" 
    /> */}
    {/* <GradePage 
      studentName="Tal"
      grade="90"
      subject="math"
      description="hello world"
    />
    <GradePage 
      studentName="Tal"
      grade="76"
      subject="igor"
      description="hello world"
    />
    <GradePage 
      studentName="Tal"
      grade="1111"
      subject="mongodb"
      description="hello world"
    />
    <GradePage 
      studentName="Tal"
      grade="100"
      subject="ui"
      description="hello world"
    /> */}
    <AdvancedGradePage 
      grade="100"
      subject="math"
      description1="hello world"
      description2="hello world"
    
    />
  </StrictMode>
)
