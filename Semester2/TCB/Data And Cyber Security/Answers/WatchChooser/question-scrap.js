import { chromium } from 'playwright';

export async function scrapeBrands() {
  const browser = await chromium.launch({ headless: false }); // Set to true in production
  const page = await browser.newPage();

  // Load the page
  try {
    console.log('Navigating to Chrono24...');
    await page.goto('https://www.chrono24.com/watches/mens-watches--62.htm', {
      waitUntil: 'domcontentloaded',
    });

    // Accept cookies
    try {
      console.log('Trying to accept cookies...');
      await page.waitForSelector('button.js-cookie-accept-all', { timeout: 5000 });
      await page.click('button.js-cookie-accept-all');
      console.log('Cookies accepted.');
    } catch {
      console.warn('Cookie banner not found or already accepted.');
    }

    // Open filter sidebar
    try {
      console.log('Waiting for filter toggle...');
      await page.waitForSelector('button.wt-filter-toggle', { timeout: 5000 });
      await page.click('button.wt-filter-toggle');
      console.log('Filter sidebar opened.');
    } catch (err) {
      console.error('Failed to open filter sidebar:', err);
    }

    // Wait for the filter options to appear
    console.log('Waiting for brand filter list...');
    await page.waitForSelector('div.filter-option-list', { timeout: 5000 });

    // Extract brand names and counts
    const brandsTemp = await page.$$eval('span.pointer', (spans) =>
      spans.map((span) => {
        const rawText = span.textContent.trim();
        const name = rawText.split('(')[0].trim();
        const count = rawText.match(/\(([\d,.]+)\)/)?.[1]?.replace(',', '');
        return { name, count: count ? parseInt(count) : 0 };
      })
    );
    const brands = brandsTemp.slice(2);
    console.log(`Extracted ${brands.length} brands.`);

    // Click on the case size filter tab
    try {
      console.log('Clicking case size tab...');
      await page.click('button.wt-nav-item-gDimensions');
      await page.waitForSelector('div[data-testid="wt-list-size"]', { timeout: 5000 }); // container of size filters
      console.log('Case size filter loaded.');
    } catch (err) {
      console.error('Failed to open case size tab:', err);
    }

    // Wait for the case size options
    console.log('Waiting for case sizes...');
    await page.waitForSelector('span.d-inline-block.p-x-3.p-y-2', { timeout: 5000 });

    const caseSizes = await page.$$eval('span.d-inline-block.p-x-3.p-y-2', (spans) => {
      return spans.map((span) => {
        const rawText = span.textContent.trim();
        const size = rawText.split('(')[0].replace(' mm', '').trim();
        return { size };
      });
    });
    console.log(`Extracted ${caseSizes.length} case sizes.`);
    

// Click on the movement filter tab
    try {
      console.log('Clicking movements and functions tab...');
      await page.click('button.wt-nav-item-gMovement');
      await page.waitForSelector('div[data-testid="wt-list-size"]', { timeout: 5000 }); // container of movement filters
      console.log('Movement filter loaded.');
    } catch (err) {
      console.error('Failed to open movement tab:', err);
    }

    console.log('Waiting for movements and functions...');
    await page.waitForSelector('div.col-xs-24.col-sm-12.col-lg-8', { timeout: 5000 });

    const movementTemp = await page.$$eval('div.col-xs-24.col-sm-12.col-lg-8', (spans) => {
      return spans.map((span) => {
        const rawText = span.textContent.trim();
        const movement = rawText.split('(')[0].replace(' mm', '').trim();
        return { movement };
      });
    });
    const movements = movementTemp.slice(0, 6);
    const functions = movementTemp.slice(6, -2).map(obj => ({ function: obj.movement }));;
    console.log(`Extracted ${movements.length} movements.`);
    console.log(`Extracted ${functions.length} functions.`);

    try {
      console.log('Clicking dial tab...');
      await page.click('button.wt-nav-item-gDials');
      await page.waitForSelector('div[data-testid="wt-list-size"]', { timeout: 5000 }); // container of movement filters
      console.log('Dial filter loaded.');
    } catch (err) {
      console.error('Failed to open dial tab:', err);
    }
    
    console.log('Waiting for dial styles and colors...');
    await page.waitForSelector('div.col-xs-24.col-sm-12.col-lg-8', { timeout: 5000 });

    const dialTemp = await page.$$eval('div.col-xs-24.col-sm-12.col-lg-8', (spans) => {
      return spans.map((span) => {
        const rawText = span.textContent.trim();
        const dial = rawText.split('(')[0].replace(' mm', '').trim();
        return { dial };
      });
    }
    );
    const dialStyle = dialTemp.slice(0, 7).map(obj => ({ dialStyle: obj.dial }));
    const dialColor = dialTemp.slice(7, -2).map(obj => ({ dialColor: obj.dial }));
    console.log(`Extracted ${dialStyle.length} dial styles.`);
    console.log(`Extracted ${dialColor.length} dial colors.`);

    try {
      console.log('Clicking band tab...');
      await page.click('button.wt-nav-item-gBracelet');
      await page.waitForSelector('div[data-testid="wt-list-size"]', { timeout: 5000 }); // container of band filters
      console.log('Band filter loaded.');
    } catch (err) {
      console.error('Failed to open band tab:', err);
    }

    console.log('Waiting for dial styles and colors...');
    await page.waitForSelector('div.col-xs-12.col-md-8', { timeout: 5000 });

    const band = await page.$$eval('div.col-xs-12.col-md-8', (spans) => {
      return spans.map((span) => {
        const rawText = span.textContent.trim();
        const band = rawText.split('(')[0].trim();
        return { band };
      });
    }
    );

    try {
      console.log('Clicking clasp tab...');
      await page.click('button.wt-nav-item-gClasp');
      await page.waitForSelector('div[data-testid="wt-list-size"]', { timeout: 5000 }); // container of clasp filters
      console.log('Clasp filter loaded.');
    } catch (err) {
      console.error('Failed to open clasp tab:', err);
    }

    console.log('Waiting for clasp styles and colors...');
    await page.waitForSelector('div.col-xs-24.col-sm-12.col-lg-8', { timeout: 5000 });

    const claspTemp = await page.$$eval('div.col-xs-24.col-sm-12.col-lg-8', (spans) => {
      return spans.map((span) => {
        const rawText = span.textContent.trim();
        const clasp = rawText.split('(')[0].trim();
        return { clasp };
      });
    }
    );
    const clasp = claspTemp.slice(0, -1).map(obj => ({ clasp: obj.clasp }));
    console.log(`Extracted ${clasp.length} clasps.`);


    await page.close(); 
    await browser.close();

    return { brands, caseSizes, movements, functions, dialStyle, dialColor, band, clasp };
  } catch (err) {
    await browser.close();
    console.error('Unexpected scraping error:', err);
    throw err;
  }
}